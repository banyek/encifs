mkdir build
cd build
cmake .. $@
make -j4
sudo checkinstall --install=no \
  --pkgname="encifs" \
  --provides="encifs"

