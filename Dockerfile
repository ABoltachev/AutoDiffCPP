FROM ubuntu:22.04

ENV TZ=Europe/Moscow
# ARG
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get install -y git

# python and pipenv
RUN apt-get install -y python3-pip python3-dev && \
    pip install --user pipenv && \
    apt-get install -y software-properties-common && \
    add-apt-repository ppa:deadsnakes/ppa && \
    apt-get install -y python3.9 python3.9-distutils

# gcc
RUN apt-get install -y gcc=4:11.2.0-1ubuntu1 g++=4:11.2.0-1ubuntu1 gdb=12.0.90-0ubuntu1

# cmake
RUN apt-get install -y cmake=3.22.1-1ubuntu1.22.04.1

# clang
RUN apt-get install -y clang=1:14.0-55~exp2 lld=1:14.0-55~exp2 llvm=1:14.0-55~exp2 \
    liblldb-dev=1:14.0-55~exp2 ninja-build=1.10.1-1
RUN git clone https://github.com/lldb-tools/lldb-mi.git && \
    cd lldb-mi && mkdir build && cd build && \
    cmake -G Ninja -DCMAKE_INSTALL_PREFIX=$INSTALL_PREFIX .. && \
    cmake --build . && \
    cmake --build . --target install && \
    ln -s /usr/bin/lldb-server-14 /usr/bin/lldb-server-14.0.0 && \
    ln -s /usr/lib/llvm-14/lib/python3.10/dist-packages/lldb/* /usr/lib/python3/dist-packages/lldb/

WORKDIR /projects

# COPY source dest
# ADD source dest

CMD ["/bin/bash", "--help"]
# ENTRYPOINT [ "executable" ]
