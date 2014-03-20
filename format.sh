#!/bin/bash
shopt -s globstar
astyle -s2 -A1 {,Commands/,Subsystems/}*.{h,cpp} && rm **/*.orig
