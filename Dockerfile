FROM centos:7

WORKDIR /root/workdir

RUN yum -y update && \
    yum -y groupinstall "Development Tools"

# COPY .bashrc /root/workdir
