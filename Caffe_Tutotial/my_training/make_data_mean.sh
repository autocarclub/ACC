#!/usr/bin/env sh
# Compute the mean image from the imagenet training lmdb
# N.B. this is available in data/ilsvrc12

EXAMPLE=/home/namntse05438/caffe-1.0/my_training/
DATA=/home/namntse05438/caffe-1.0/my_training/
TOOLS=build/tools

$TOOLS/compute_image_mean $EXAMPLE/data_train_lmdb \
  $DATA/data_mean.binaryproto

echo "Done."
