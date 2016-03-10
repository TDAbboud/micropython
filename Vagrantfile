# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/trusty64"

  config.vm.provider "virtualbox" do |vb|
    # vb.gui = true
    vb.memory = 1024
    # Turn on USB 2.0 support, requires the VirtualBox Extras to be installed
    # vb.customize ["modifyvm", :id, "--usb", "on", "--usbehci", "on"]
    # Setup rule to automatically attach ST Link v2.1 Debugger when plugging in Nucleo board
    # BetterUSB.usbfilter_add(vb, "0x0483", "0x374b", "ST Link v2.1 Nucleo")

  end

  config.vm.synced_folder(".", "/vagrant/micropython",
    :owner => "vagrant",
    :group => "vagrant",
    :mount_options => ['dmode=777','fmode=777']
  )

  # Provision the system
  config.vm.provision "shell", inline: <<-SHELL
    # Install micropython dependencies
    add-apt-repository -y ppa:terry.guo/gcc-arm-embedded
    dpkg --add-architecture i386
    apt-get update -qq
    apt-get install -y gcc git python3 python3-dev gcc-multilib gcc-arm-none-eabi pkg-config libffi-dev libffi-dev:i386

    # Make unix and stmhal port
    cd /vagrant/micropython
    make -C unix deplibs
    make -C unix
    make -C stmhal
    echo "All DONE...Run vagrant ssh to connect!"
  SHELL
end
