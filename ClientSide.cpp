 #include <iostream>
 #include <cstring>
 #include <unistd.h>
 #include <arpa/inet.h>
 int main() {
 
 int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
 
 if (clientSocket ==-1) {
 std::cerr << "Error creating socket." << std::endl;
 return-1;
 }

 sockaddr_in serverAddress;
 serverAddress.sin_family = AF_INET;
 serverAddress.sin_port = htons(8080); 
 if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0) {
 std::cerr << "Invalid address/Address not supported." << std::endl;
 close(clientSocket);
 return-1;
 }
 
 if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) ==-1) {
 std::cerr << "Connection failed." << std::endl;
 close(clientSocket);
 return-1;
 }
 std::cout << "Connected to the server. Sending data..." << std::endl;
 
 const char* message = "Hello from the client!";
 if (send(clientSocket, message, strlen(message), 0) ==-1) {
 std::cerr << "Error sending data." << std::endl;
 close(clientSocket);
 return-1;
 }
 
 close(clientSocket);
 return 0;
 }

