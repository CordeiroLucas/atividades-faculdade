import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("192.168.0.10", 8080))

full_msg = ''
while True:
	msg = client.recv(1024)
	if len(msg) <= 0:
		break
	full_msg += msg.decode("utf-8")
	client.send(bytes("Bom dia Server", "utf-8"))

print(full_msg)


               