 #include <iostream>
 #include <cstring>
 #include <unistd.h>
 #include <arpa/inet.h>
 int main() {
 
 int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
 
 if (serverSocket ==-1) {
 std::cerr << "Error creating socket." << std::endl;
 return-1;
 }
 
 sockaddr_in serverAddress;
 serverAddress.sin_family = AF_INET;
 serverAddress.sin_addr.s_addr = INADDR_ANY;
 serverAddress.sin_port = htons(8080);
 if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) ==-1) {
 std::cerr << "Error binding socket." << std::endl;
 close(serverSocket);
 return-1;
 }
 
 if (listen(serverSocket, 5) ==-1) {
 std::cerr << "Error listening for connections." << std::endl;
 close(serverSocket);
}
 return-1;
 std::cout << "Server listening on port 8080..." << std::endl;
 
 sockaddr_in clientAddress;
 socklen_t clientAddrSize = sizeof(clientAddress);
 int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrSize);
 
 if (clientSocket ==-1) {
 std::cerr << "Error accepting connection." << std::endl;
 close(serverSocket);
 return-1;
 }
 std::cout << "Connection accepted. Waiting for data..." << std::endl;
 
 char buffer[1024];
 ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

 if (bytesRead ==-1) {
 std::cerr << "Error receiving data." << std::endl;
 close(serverSocket);
 close(clientSocket);
 return-1;
 }
 
 std::cout << "Received data from client: " << buffer << std::endl;
 
 close(serverSocket);
 close(clientSocket);
 return 0;
 }
