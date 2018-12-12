#!/usr/bin/env sh
set -e

./build/tools/caffe train --solver=/home/namntse05438/caffe-1.0/my_training/models/solver.prototxt $@
