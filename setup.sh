#!/bin/bash

function clean() {
	rm -rf 3rdparty
	rm -rf build
}

function install_sfml() {
	mkdir SFML-TEMP
	cd SFML-TEMP
	curl https://github.com/SFML/SFML/archive/2.5.1.tar.gz -L -o repository.tar.gz
	mkdir repository
	tar -xzf repository.tar.gz --strip=1 -C repository
	rm repository.tar.gz
	cd repository
	cmake -S . -B ../generated -DCMAKE_INSTALL_PREFIX=../../3rdparty/SFML
	cd ..
	cd generated
	cmake --build . --target install --config Debug
	cmake --build . --target install --config Release
	cd ../../
	rm -rf SFML-TEMP
}

function install() {
	install_sfml
}

function generate() {
	cmake -S . -B ./build
}

function copy_dll {
	mkdir -p bin/Debug bin/Release

	debug=( sfml-graphics-d-2.dll sfml-window-d-2.dll sfml-system-d-2.dll )
	for i in "${debug[@]}"
	do
		cp -f 3rdparty/SFML/bin/$i bin/Debug/$i
	done

	release=( sfml-graphics-2.dll sfml-window-2.dll sfml-system-2.dll )
	for i in "${release[@]}"
	do
		cp -f 3rdparty/SFML/bin/$i bin/Release/$i
	done
}

while getopts "cigda" o; do
	case "${o}" in
		a)
			clean
			install
			generate
			copy_dll
			;;
		c)
			clean
			;;
		i)
			install
			;;
		g)
			generate
			;;
		d)
			copy_dll
			;;
	esac
done
