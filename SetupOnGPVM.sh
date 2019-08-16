#!/bin/bash


source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh

function latest {
    product=$1
    quals=$2
    version=v`ups list -aK"VERSION" $product $quals | uniq | sed -e 's/v//' -e 's/\"//g' | sort -n | tail -1`
    if [ "X$quals" == "X" ]; then
        quals=`ups list -aK"QUALIFIERS" $product $version | grep "prof" | grep -v "noifdh" | sed -e 's/\"//g' | uniq | sort -n | tail -1`
        if [ "X$quals" != "X" ]; then
            quals="-q $quals"
        fi
    fi

    echo "$product $version $quals"
}


setup `latest gcc`
setup `latest cmake`
setup `latest root`
