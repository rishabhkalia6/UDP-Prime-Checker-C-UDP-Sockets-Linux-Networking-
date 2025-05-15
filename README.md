# 🔎 UDP Prime Checker – (C, UDP Sockets, Linux Networking)

This project demonstrates a basic client-server architecture using **UDP sockets in C**. The client sends a number to the server, which checks whether the number is prime and sends back a boolean response. It's a simple yet practical example of **low-level network communication**, **UDP datagram handling**, and **server-side computation logic**.

---

## 📦 Features

- Lightweight UDP communication

- Client-server model over IPv4
  
-  logic implemented server-side

- Minimal and modular C code

- No external libraries required

---

## ⁉️Why this project matters

Unlike TCP, UDP is a **connectionless protocol**, which makes it lightweight but also less reliable. Handling UDP properly requires understanding:
- Datagram packet boundaries
- Manual message validation
- Non-blocking behavior and error handling

---

## 🗄️ Project file structure

- **``udpClient.c``**
This is the **client-side program**. It prompts the user to enter an integer, then sends that number to the server using a UDP socket. After sending, it waits for the server's response and prints whether the number is prime. It demonstrates:
    - UDP socket creation and communication
    - Basic input handling and data formatting
    - Receiving server responses over datagram

- **``udpServer.c``**
This is the **server-side program**. It listens on a fixed port for incoming UDP datagrams. Upon receiving a number from a client, it checks if the number is prime and sends the result (1 for prime, 0 for not) back to the client. It demonstrates:
    - Handling incoming UDP packets
    - Stateless communication logic
    - Server-side computation and response generation

---

## ✨ How does it work? (Client-side)

- Client-side (**``udpClient.c``**)
```C
sendto(sock, &number, sizeof(number), 0,
       (struct sockaddr *)&server_addr, sizeof(server_addr));

recvfrom(sock, &is_prime, sizeof(is_prime), 0,
         (struct sockaddr *)&server_addr, &addr_len);
```
This shows how the client:
  - **Sends an integer to the server**
  - **Waits to receive a response (1 or 0 for prime)**

---

## ✨ How does it work? (Server-side)

- Server-side (**``udpServer.c``**)
``` C
recvfrom(sock, &number, sizeof(number), 0,
         (struct sockaddr *)&client_addr, &addr_len);

int is_prime = check_prime(number);

sendto(sock, &is_prime, sizeof(is_prime), 0,
       (struct sockaddr *)&client_addr, addr_len);
```
This shows how the server:

- **Receives a number from the client**
- **Calls the check_prime() function**
- **Sends back the result to the client**

---

## 💻 Output
