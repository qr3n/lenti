sudo losetup --offset $((512*2048)) --sizelimit $((512*206847)) --show --find emulator.img
sudo mkfs.fat -F16 /dev/loop0
sudo mount /dev/loop0 /mnt
sudo mkdir /mnt/EFI
sudo mkdir /mnt/EFI/boot
sudo cp bootx64.efi /mnt/EFI/boot
sudo cp config.lenti /mnt
sudo losetup -d /dev/loop0
sudo umount /mnt
sudo qemu-system-x86_64 -enable-kvm -bios OVMF.fd -hda emulator.img