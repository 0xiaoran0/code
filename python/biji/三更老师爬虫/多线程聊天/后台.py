from socket import *
# server_socket = socket(AF_INET, SOCK_STREAM)         # ?
server_socket = socket()
server_socket.bind(('0.0.0.0', 8888))