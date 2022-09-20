#include "stdlib.h"
#include "sifdev.h"
#include "string.h"
#include "stdio.h"
#include "elf.h"

static char* elf_types[] = {
    "No file type",
    "Relocatable file",
    "Executable file",
    "Shared object file",
    "Core file",
};

static int apply_reloc(u8 * reloc, int type, u32 addr) {
    u32 u_current_data;
    s32 s_current_data;
	u32 newstate;

	if (((u32)reloc)&0x3)
	{
		printf("Unaligned reloc (%p) type=%d!\n", reloc, type);
	}
	memcpy(&u_current_data, reloc, 4);
	memcpy(&s_current_data, reloc, 4);

    switch (type) {
	case R_MIPS_32:
		newstate = s_current_data + addr;
		break;
	case R_MIPS_26:
		newstate = (u_current_data & 0xfc000000) | (((u_current_data & 0x03ffffff) + (addr >> 2)) & 0x3ffffff);
		break;
	case R_MIPS_HI16:
		newstate = (u_current_data & 0xffff0000) | ((((s_current_data << 16) >> 16) + (addr >> 16) + ((addr & 0xffff) >= 0x8000 ? 1 : 0)) & 0xffff);
		break;
	case R_MIPS_LO16:
		newstate = (u_current_data & 0xffff0000) | ((((s_current_data << 16) >> 16) + (addr & 0xffff)) & 0xffff);
		break;
	default:
		return -1;
    }

	memcpy(reloc, &newstate, 4);

    printf("Changed data at %08X from %08X to %08X.\n", reloc, u_current_data, newstate);
    return 0;
}


int load_default_plugins(){
    elf_header_t elf_header;
    section_header_t shstr_header;
    struct sce_dirent dirbuf;
    char* section_names = NULL;
    char plugin_dir[] = "mass:PS2_SA/plugins/";
    char* dest_file = NULL;

    int dirfd = sceDopen(plugin_dir);

    sceDread(dirfd, &dirbuf);
    sceDread(dirfd, &dirbuf);

    while (sceDread(dirfd, &dirbuf) > 0){
        dest_file = (char*)malloc[0](strlen(plugin_dir) + strlen(dirbuf.d_name) + 1);

        strcpy(dest_file, plugin_dir);
        strcat(dest_file, dirbuf.d_name);

        int elf = sceOpen(dest_file, 1);

        free[0](dest_file);

        sceRead(elf, &elf_header, sizeof(elf_header_t));

        printf("Plugin loader: Loading %s - type: %s\n", dirbuf.d_name, elf_types[elf_header.type]);

        if(elf_header.type == 2){

            sceLseek(elf, elf_header.shoff + elf_header.shstrndx * sizeof(section_header_t), SEEK_SET);
            sceRead(elf, &shstr_header, sizeof(section_header_t));

            section_names = (char*)malloc[0](shstr_header.sh_size);
            sceLseek(elf, shstr_header.sh_offset, SEEK_SET);
            sceRead(elf, section_names, shstr_header.sh_size);

            section_header_t* section_header = (section_header_t*)malloc[0](sizeof(section_header_t)*elf_header.shnum);

            sceLseek(elf, elf_header.shoff, SEEK_SET);
            sceRead(elf, section_header, sizeof(section_header_t)*elf_header.shnum);

            for(int j = 0; j < elf_header.shnum; j++){
                printf("Plugin loader: %s section - address: 0x%x | offset: 0x%x | size: %d\n", section_names + section_header[j].sh_name, section_header[j].sh_addr, section_header[j].sh_offset, section_header[j].sh_size);
            }

            sceLseek(elf, section_header[1].sh_offset, SEEK_SET);
            sceRead(elf, (void*)section_header[1].sh_addr, section_header[1].sh_size);

            free[0](section_names);
            free[0](section_header);
        }

        sceClose(elf);
    }

    return 0;

}