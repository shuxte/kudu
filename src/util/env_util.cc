// Copyright (c) 2013, Cloudera, inc.
// All rights reserved.

#include <tr1/memory>

#include <string>

#include "util/env.h"
#include "util/env_util.h"
#include "util/status.h"

namespace kudu {
namespace env_util {

using std::tr1::shared_ptr;

Status OpenFileForWrite(Env *env, const string &path,
                        shared_ptr<WritableFile> *file) {
  WritableFile *w;
  RETURN_NOT_OK(env->NewWritableFile(path, &w));
  file->reset(w);
  return Status::OK();
}

Status OpenFileForRandom(Env *env, const string &path,
                         shared_ptr<RandomAccessFile> *file) {
  RandomAccessFile *r;
  RETURN_NOT_OK(env->NewRandomAccessFile(path, &r));
  file->reset(r);
  return Status::OK();
}

Status OpenFileForSequential(Env *env, const string &path,
                             shared_ptr<SequentialFile> *file)
{
  SequentialFile *r;
  RETURN_NOT_OK(env->NewSequentialFile(path, &r));
  file->reset(r);
  return Status::OK();
}

} // namespace env_util
} // namespace kudu
