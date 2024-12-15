import socket

class UDPSocket:
    def __init__(self):
        """Initialize the UDP socket."""
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.settimeout(5) 

    def __del__(self):
        """Clean up the socket."""
        self.sock.close()

    def send_datagram(self, msg: bytes, address: tuple):
        try:
            bytes_sent = self.sock.sendto(msg, address)
            return bytes_sent
        except socket.timeout:
            print("Error: Connection timed out.")
            return -1
        except Exception as e:
            print(f"Error sending datagram: {e}")
            return -1

    def recv_datagram(self, bufsize: int):
        try:
            data, addr = self.sock.recvfrom(bufsize)
            return data, addr
        except socket.timeout:
            print("Error: Timeout while waiting for a response.")
            return None, None
        except Exception as e:
            print(f"Error receiving datagram: {e}")
            return None, None

if __name__ == "__main__":
    SERVER = "127.0.0.1"
    PORT = 8888
    BUFLEN = 1024

    client_sock = UDPSocket()
    server_address = (SERVER, PORT)

    print(f"Client initialized. Server address: {SERVER}, port: {PORT}")

    while True:
        try:
            message = input("Enter message (or type 'exit' to quit): ").strip()
            if not message:
                print("Please enter a non-empty message.")
                continue
            if message.lower() == "exit":
                print("Client shutting down.")
                break

            bytes_sent = client_sock.send_datagram(message.encode(), server_address)
            if bytes_sent == -1:
                print("Failed to send message.")
                continue

            data, _ = client_sock.recv_datagram(BUFLEN)
            if data:
                print(f"Received from server: {data.decode()}")
            else:
                print("No response from server.")

        except KeyboardInterrupt:
            print("\nClient shutting down.")
            break
