FROM golang:alpine3.18
ADD main.go /root
WORKDIR /root
RUN go build -o /root/mainAPP /root/main.go

FROM alpine:latest
WORKDIR /root
COPY --from=0 /root/mainAPP .
CMD ["./mainAPP"]
