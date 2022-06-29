package main

import (
	"fmt"
	"net"
)

func main() {
	dstream, err := net.Listen("tcp", ":5893")

	if err != nil {
		fmt.Println(err) //
		return
	}
	defer dstream.Close()

	for {
		con, err := dstream.Accept()
		if err != nil {
			fmt.Println(err) //
			return
		}

		go handle(con)
	}
}

func handle(con net.Conn) {
	defer con.Close()
	for {
		buf := make([]byte, 32) // 32 - размер сообщения в байтах

		rlen, err := con.Read(buf)
		if err != nil {
			fmt.Println(err) //
			return
		}
		con.Write(buf[:rlen])
	}
}
