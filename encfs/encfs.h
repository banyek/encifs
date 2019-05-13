/*****************************************************************************
 * Author:   Valient Gough <vgough@pobox.com>
 *
 *****************************************************************************
 * Copyright (c) 2003, Valient Gough
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _encifs_incl_
#define _encifs_incl_

#include "easylogging++.h"
#include <fuse.h>
#include <sys/types.h>
#include <unistd.h>

#include "config.h"

namespace encifs {

#if defined(HAVE_SYS_XATTR_H) | defined(HAVE_ATTR_XATTR_H)
#define HAVE_XATTR
#endif

#ifndef __linux__
#include <cerrno>

static __inline int setfsuid(uid_t uid) {
  uid_t olduid = geteuid();

  if (seteuid(uid) != 0) {
    return -1;
  }

  return olduid;
}

static __inline int setfsgid(gid_t gid) {
  gid_t oldgid = getegid();

  if (setegid(gid) != 0) {
    return -1;
  }

  return oldgid;
}
#endif

int encifs_getattr(const char *path, struct stat *stbuf);
int encifs_fgetattr(const char *path, struct stat *stbuf,
                   struct fuse_file_info *fi);
int encifs_readlink(const char *path, char *buf, size_t size);
int encifs_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                  off_t offset, struct fuse_file_info *finfo);
int encifs_mknod(const char *path, mode_t mode, dev_t rdev);
int encifs_mkdir(const char *path, mode_t mode);
int encifs_unlink(const char *path);
int encifs_rmdir(const char *path);
int encifs_symlink(const char *from, const char *to);
int encifs_rename(const char *from, const char *to);
int encifs_link(const char *to, const char *from);
int encifs_chmod(const char *path, mode_t mode);
int encifs_chown(const char *path, uid_t uid, gid_t gid);
int encifs_truncate(const char *path, off_t size);
int encifs_ftruncate(const char *path, off_t size, struct fuse_file_info *fi);
int encifs_utime(const char *path, struct utimbuf *buf);
int encifs_open(const char *path, struct fuse_file_info *info);
int encifs_create(const char *path, mode_t mode, struct fuse_file_info *info);
int encifs_release(const char *path, struct fuse_file_info *info);
int encifs_read(const char *path, char *buf, size_t size, off_t offset,
               struct fuse_file_info *info);
int encifs_write(const char *path, const char *buf, size_t size, off_t offset,
                struct fuse_file_info *info);
int encifs_statfs(const char *, struct statvfs *fst);
int encifs_flush(const char *, struct fuse_file_info *info);
int encifs_fsync(const char *path, int flags, struct fuse_file_info *info);

#ifdef HAVE_XATTR

#ifdef XATTR_ADD_OPT
int encifs_setxattr(const char *path, const char *name, const char *value,
                   size_t size, int flags, uint32_t position);
int encifs_getxattr(const char *path, const char *name, char *value, size_t size,
                   uint32_t position);
#else
int encifs_setxattr(const char *path, const char *name, const char *value,
                   size_t size, int flags);
int encifs_getxattr(const char *path, const char *name, char *value,
                   size_t size);
#endif

int encifs_listxattr(const char *path, char *list, size_t size);
int encifs_removexattr(const char *path, const char *name);
#endif

int encifs_utimens(const char *path, const struct timespec ts[2]);

}  // namespace encifs

#endif
