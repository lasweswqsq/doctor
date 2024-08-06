import socket

sk = socket.socket()
sk.bind(('127.0.0.1', 9000))  # 申请操作系统的资源
sk.listen()
print(sk)


while True:
    print(f'sk:{sk}')
    # conn里存储的是一个客户端和服务端的连接信息
    conn, adder = sk.accept()  # 能够和多个客户端进行握手了
    print(f'conn:{conn}')
    conn.send(b'hello')
    msg = conn.recv(1024)
    print(msg)
    conn.close()  # 挥手，断开连接

sk.close()  # 归还申请的操作系统的资源


