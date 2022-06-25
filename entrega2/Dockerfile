FROM debian:latest

RUN apt-get update && \
  apt-get install -y\
  libc-dev-bin \
  libntirpc-dev \
  rpcbind \
  build-essential

WORKDIR /server

COPY entrega2*.c entrega2.h entrega2.x Makefile ./