FROM ubuntu:22.04

LABEL maintainer="Incheon National University geunchanlee Maintainers <rmscks97@inu.ac.kr>"

RUN apt-get update
RUN apt-get install apache2 -y
ADD test.html /var/www/html
WORKDIR /var/www/html
RUN ["/bin/bash", "-c", "echo hello >> test2.html"]
EXPOSE 80
CMD apachectl -DFOREGROUND