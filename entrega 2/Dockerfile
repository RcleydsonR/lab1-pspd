FROM debian:latest

RUN apt-get update && \
  apt-get install -y\
  libc-dev-bin \
  libntirpc-dev \
  rpcbind \
  build-essential

WORKDIR /server

COPY lab1*.c lab1.h lab1.x Makefile.other ./
RUN mv Makefile.other Makefile
