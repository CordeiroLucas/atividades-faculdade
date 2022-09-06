import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(("192.168.0.10", 8080))
serv.listen((5))


full_msg = ''
while True:
        clientsocket, address = serv.accept()
        print(f"Connection from {address} has been established!")

        clientsocket.send(bytes("Welcome to the Server!", "utf-8"))
        
        while True:
                msg = clientsocket.recv(1024)
                full_msg = msg.decode("utf-8")
                
                if msg.decode("utf-8") == "quit":
                        clientsocket.close()
                        print(f"Client {address} disconnected!\n")
                        break
                else: print(full_msg)

        
        
serv.close()

       