#!/usr/bin/env bash
cp jedit JEdit_1.0-1_any/usr/local/bin/jedit 
dpkg-deb --build --root-owner-group JEdit_1.0-1_any packages