import socket

host = socket.gethostbyname(socket.gethostname())
port = 2000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen(4)

print("SERVER STARTED ON HOST: ", host, ":", port, sep="")

client_socket, adress = server.accept()
while True:
    data = client_socket.recv(1024).decode('utf-8')
    print(adress, *data)

    content = data.encode('utf-8')
    client_socket.send(content)
