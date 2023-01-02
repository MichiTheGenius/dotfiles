#!/bin/bash
let CURRENT=$(xbacklight -get)
let NEW=$CURRENT+10
xbacklight -set $NEW
