#!/bin/bash

NU=${NU:-0.00001} #Re=4000

FACTORY=" StefanFish L=0.2 T=1 xpos=1.0 ypos=1.0 zpos=1.0 bFixFrameOfRef=0 heightProfile=danio widthProfile=stefan bFixToPlanar=1"
OPTIONS=
OPTIONS+=" -bpdx 4 -bpdy 4 -bpdz 4 -extentx 2.0 -levelMax 7 -levelStart 4 "
OPTIONS+=" -Rtol 10000.00 -Ctol 100.00"
OPTIONS+=" -fsave 0 -tdump 0 -tend 0 "
OPTIONS+=" -CFL 0.7 -lambda 1e6 -nu ${NU}"
OPTIONS+=" -poissonTol 1e-6 -poissonTolRel 1e-3 -bMeanConstraint 1"
