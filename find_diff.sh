#!/bin/bash
echo "---------STARTING FOLDER COMPARISON---------"
if !(diff -qrN ./CC2/files_report/ ./C2/files_report/) ; then
  	echo "folders aren't equal!"
  	echo "TEST SUCCESS"
  	exit 1
else
	echo "folders are equal!"
	echo "---------TEST SUCCESS---------"
fi