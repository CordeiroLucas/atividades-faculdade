import socket
import threading

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(("192.168.0.10", 8080))
serv.listen((5))

while True:
        clientsocket, address = serv.accept()
        print(f"Connection from {address} has been established!")

        clientsocket.send(bytes("Welcome to the Server!", "utf-8"))
        i = 0
        while True:
                msg = clientsocket.recv(1024)
                full_msg = msg.decode("utf-8")
                
                if full_msg == "quit":
                        clientsocket.close()
                        print(f"Client {address} disconnected!\n")
                        break
                else:
                        print(f"Package {i}: {full_msg}")
                        i+=1
                

        
        
serv.close()

       