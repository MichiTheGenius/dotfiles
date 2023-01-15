#!/bin/sh
set -xe

wget http://ftp.us.debian.org/debian/pool/main/libs/libseccomp/libseccomp2_2.5.1-1~bpo10+1_armhf.deb
sudo dpkg -i libseccomp2_2.5.1-1~bpo10+1_armhf.deb
