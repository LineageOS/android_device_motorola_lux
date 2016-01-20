#!/bin/sh

set -e

export DEVICE=lux
export VENDOR=motorola
./../../$VENDOR/msm8916-common/setup-makefiles.sh $@
