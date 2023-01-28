#!/bin/bash
let CURRENT=$(xbacklight -get)

#if [ $CURRENT -gt 10 ]
#then
let NEW=$CURRENT-10
xbacklight -set $NEW
#fi
