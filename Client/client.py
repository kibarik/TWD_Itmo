#!/usr/bin/python3.7
# -*- coding: utf-8 -*-

import socket
import time
from random import randint

sock = socket.socket()
sock.connect(('192.168.1.39', 6000))
#data = sock.recv(1024)
sock.send(b"-1")
data = sock.recv(1024)
print(str(data))
id = data

while(True):
  request = [str(int(id))]
  if (randint(0, 9) == 0):
    request.append('0')
  request.append(str(randint(1, 6)))
  print(bytes("|".join(request).encode()))
  sock.send(bytes("|".join(request).encode()))
  time.sleep(randint(0, 1))

sock.close()
