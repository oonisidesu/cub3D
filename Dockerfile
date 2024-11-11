FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    libxext-dev \
    libx11-dev \
    libbsd-dev \
    libxrandr-dev \
    libxrender-dev \
    libxfixes-dev \
    libxinerama-dev \
    libxcursor-dev \
    make \
    gcc

WORKDIR /cub3d
COPY . .

RUN make

CMD ["./cub3D", "map.cub"]