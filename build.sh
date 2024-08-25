# build dependencies
# Google Test
pushd ./include/googletest/
mkdir build > /dev/null 2> /dev/null
cd build
cmake .. -DBUILD_GMOCK=OFF
make
popd

# build main project
fbuild