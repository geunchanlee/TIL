FROM golang:alpine3.18
ADD main.go /root
WORKDIR /root
RUN go build -o /root/mainAPP /root/main.go
CMD ["./mainAPP"]