import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(("192.168.0.10", 8080))
serv.listen((5))

full_msg = ''
while True:
        clientsocket, address = serv.accept()
        print(f"Connection from {address} has been established!")
<<<<<<< HEAD
        clientsocket.send(bytes("Welcome to the Server!\n", "utf-8"))

        clientsocket.close()
        print(f"Client {address} disconnected!\n")
=======
        clientsocket.send(bytes("Welcome to the Server!", "utf-8"))
        
        while True:
                msg = clientsocket.recv(1024)
                full_msg = msg.decode("utf-8")
                
                if msg.decode("utf-8") == "quit":
                        clientsocket.close()
                        print(f"Client {address} disconnected!\n")
                        break
                else: print(full_msg)
>>>>>>> 8a349f728215adda23b364cef4132b462ea7121b
        
        
serv.close()

       