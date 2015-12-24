
dpkg -S `which ps`


apt-get source procps


fix ps/output.c


dpkg-source --commit


dpkg-buildpackage -D -us -uc


diff: diff -Naur a/ b/ > patch.diff



chrt -b 0 nice -3 ps/ps fo pid,cls,ni,cmd
  PID CLS  NI CMD
 6312  TS   0 -bash
15254   B   3  \_ ps/ps fo pid,cls,ni,cmd
 3657  TS   0 -bash

