import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(("26.135.226.163", 8080))
serv.listen((5))

while True:
        clientsocket, address = serv.accept()
        print(f"Connection from {address} has been established!")
        clientsocket.send(bytes("Welcome to the Server!\n", "utf-8"))
        clientsocket.send(bytes("bondia\n", "utf-8"))

        clientsocket.close()
        print(f"Client {address} disconnected!\n")
        
        
serv.close()

       