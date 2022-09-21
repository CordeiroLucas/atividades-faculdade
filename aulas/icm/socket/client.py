import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("0.0.0.0", 8030))

nomeCliente = ''

while True:
	full_msg = ''
	msg = client.recv(1024)
	print(msg.decode("utf-8"))
	if len(msg) <= 0:
		break

	nomeCliente = input("Nome: ")

	full_msg += msg.decode("utf-8")
 
	while True:
		enviar = input(f"{nomeCliente}> ")
		client.send(bytes(enviar, "utf-8"))
		if enviar == "quit":
			exit(0)
		elif enviar == "shutdown":
			exit(0)
		break

print(full_msg)


               