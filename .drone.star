# Use, modification, and distribution are
# subject to the Boost Software License, Version 1.0. (See accompanying
# file LICENSE.txt)
#
# Copyright Rene Rivera 2020.

# For Drone CI we use the Starlark scripting language to reduce duplication.
# As the yaml syntax for Drone CI is rather limited.
#
#
globalenv={}
linuxglobalimage="cppalliance/droneubuntu1604:1"
windowsglobalimage="cppalliance/dronevs2019"

def main(ctx):
  return [
  linux_cxx("TOOLSET=gcc CXXSTD=98,0x Job 0", "g++", packages="g++-4.4", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '98,0x', 'TRAVIS_COMPILER': 'g++-4.4', 'DRONE_JOB_UUID': 'b6589fc6ab'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,0x Job 1", "g++", packages="g++-4.6", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,0x', 'TRAVIS_COMPILER': 'g++-4.6', 'DRONE_JOB_UUID': '356a192b79'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11 Job 2", "g++", packages="g++-4.7", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11', 'TRAVIS_COMPILER': 'g++-4.7', 'DRONE_JOB_UUID': 'da4b9237ba'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11 Job 3", "g++", packages="g++-4.8", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11', 'TRAVIS_COMPILER': 'g++-4.8', 'DRONE_JOB_UUID': '77de68daec'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11 Job 4", "g++", packages="g++-4.9", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11', 'TRAVIS_COMPILER': 'g++-4.9', 'DRONE_JOB_UUID': '1b64538924'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11,14,1z Job 5", "g++", packages="g++-5", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'g++-5', 'DRONE_JOB_UUID': 'ac3478d69a'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11,14,1z Job 6", "g++", packages="g++-6", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'g++-6', 'DRONE_JOB_UUID': 'c1dfd96eea'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11,14,17 Job 7", "g++", packages="g++-7", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,17', 'TRAVIS_COMPILER': 'g++-7', 'DRONE_JOB_UUID': '902ba3cda1'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11,14,17,2a Job 8", "g++", packages="g++-8", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'g++-8', 'DRONE_JOB_UUID': 'fe5dbbcea5'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11,14,17,2a Job 9", "g++", packages="g++-9", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'g++-9', 'DRONE_JOB_UUID': '0ade7c2cf9'}, globalenv=globalenv),
  linux_cxx("TOOLSET=gcc CXXSTD=03,11,14,17,2a Job 10", "g++", packages="g++-10", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1804:1", environment={'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'g++-10', 'DRONE_JOB_UUID': 'b1d5781111'}, globalenv=globalenv),
  linux_cxx("UBSAN=1 TOOLSET=gcc CXXSTD=03,11,14,17,2a UBS Job 11", "g++", packages="g++-9", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'UBSAN': '1', 'TOOLSET': 'gcc', 'CXXSTD': '03,11,14,17,2a', 'UBSAN_OPTIONS': 'print_stacktrace=1', 'LINKFLAGS': '-fuse-ld=gold', 'TRAVIS_COMPILER': 'g++-9', 'DRONE_JOB_UUID': '17ba079149'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11 Job 12", "clang++", packages="clang-3.3", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1404:1", environment={'TOOLSET': 'clang', 'CXXSTD': '03,11', 'TRAVIS_COMPILER': '/usr/bin/clang++', 'DRONE_JOB_UUID': '7b52009b64'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11 Job 13", "clang++", packages="clang-3.4", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1404:1", environment={'TOOLSET': 'clang', 'CXXSTD': '03,11', 'TRAVIS_COMPILER': '/usr/bin/clang++', 'DRONE_JOB_UUID': 'bd307a3ec3'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 14", "clang++", packages="clang-3.5", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-3.5', 'DRONE_JOB_UUID': 'fa35e19212'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 15", "clang++", packages="clang-3.6", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-3.6', 'DRONE_JOB_UUID': 'f1abd67035'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 16", "clang++", packages="clang-3.7", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-3.7', 'DRONE_JOB_UUID': '1574bddb75'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 17", "clang++", packages="clang-3.8", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-3.8', 'DRONE_JOB_UUID': '0716d9708d'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 18", "clang++", packages="clang-3.9", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-3.9', 'DRONE_JOB_UUID': '9e6a55b6b4'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 19", "clang++", packages="clang-4.0", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-4.0', 'DRONE_JOB_UUID': 'b3f0c7f6bb'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 20", "clang++", packages="clang-5.0", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-5.0', 'DRONE_JOB_UUID': '91032ad7bb'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,17,2a Job 21", "clang++", packages="clang-6.0", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'clang++-6.0', 'DRONE_JOB_UUID': '472b07b9fc'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,17,2a Job 22", "clang++", packages="clang-7", llvm_os="xenial", llvm_ver="7", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'clang++-7', 'DRONE_JOB_UUID': '12c6fc06c9'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,17,2a Job 23", "clang++", packages="clang-8", llvm_os="xenial", llvm_ver="8", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'clang++-8', 'DRONE_JOB_UUID': 'd435a6cdd7'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,17,2a Job 24", "clang++", packages="clang-9", llvm_os="xenial", llvm_ver="9", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'clang++-9', 'DRONE_JOB_UUID': '4d134bc072'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,17,2a Job 25", "clang++", packages="clang-10", llvm_os="xenial", llvm_ver="10", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1604:1", environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,17,2a', 'TRAVIS_COMPILER': 'clang++-10', 'DRONE_JOB_UUID': 'f6e1126ced'}, globalenv=globalenv),
  linux_cxx("UBSAN=1 TOOLSET=clang CXXSTD=03,11,14,17,2a U Job 26", "clang++", packages="clang-8", llvm_os="xenial", llvm_ver="8", buildtype="boost", buildscript="drone", image=linuxglobalimage, environment={'UBSAN': '1', 'TOOLSET': 'clang', 'CXXSTD': '03,11,14,17,2a', 'UBSAN_OPTIONS': 'print_stacktrace=1', 'TRAVIS_COMPILER': 'clang++-8', 'DRONE_JOB_UUID': '887309d048'}, globalenv=globalenv),
  linux_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 27", "clang++", packages="libc++-dev", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1404:1", environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++-libc++', 'DRONE_JOB_UUID': 'bc33ea4e26'}, globalenv=globalenv),
  linux_cxx("UBSAN=1 TOOLSET=clang CXXSTD=03,11,14,1z UBSA Job 28", "clang++", packages="libc++-dev", buildtype="boost", buildscript="drone", image="cppalliance/droneubuntu1404:1", environment={'UBSAN': '1', 'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'UBSAN_OPTIONS': 'print_stacktrace=1', 'TRAVIS_COMPILER': 'clang++-libc++', 'DRONE_JOB_UUID': '0a57cb53ba'}, globalenv=globalenv),
  osx_cxx("TOOLSET=clang CXXSTD=03,11,14,1z Job 29", "clang++", packages="", buildtype="boost", buildscript="drone", environment={'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'TRAVIS_COMPILER': 'clang++', 'DRONE_JOB_UUID': '7719a1c782'}, globalenv=globalenv),
  osx_cxx("UBSAN=1 TOOLSET=clang CXXSTD=03,11,14,1z UBSA Job 30", "clang++", packages="", buildtype="boost", buildscript="drone", environment={'UBSAN': '1', 'TOOLSET': 'clang', 'CXXSTD': '03,11,14,1z', 'UBSAN_OPTIONS': 'print_stacktrace=1', 'TRAVIS_COMPILER': 'clang++', 'DRONE_JOB_UUID': '22d200f867'}, globalenv=globalenv),
    ]

# from https://github.com/boostorg/boost-ci
load("@boost_ci//ci/drone/:functions.star", "linux_cxx","windows_cxx","osx_cxx","freebsd_cxx")
