/*
 * Copyright 2021 Hewlett Packard Enterprise Development LP
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CHPL_TYPES_COMPOSITE_TYPE_H
#define CHPL_TYPES_COMPOSITE_TYPE_H

#include "chpl/types/Type.h"

namespace chpl {
namespace types {


/**
  This class represents an aggregate type which is a type that contains other
  elements - Class, Record, Union, and Tuple types.

 */
class CompositeType : public Type {
 protected:
  // TODO: add fields and accessors for a QualifiedType per field

  bool isGeneric_ = false;

  CompositeType(typetags::TypeTag tag)
    : Type(tag) {
  }

  bool compositeTypeContentsMatchInner(const CompositeType* other) const {
    return isGeneric_ == other->isGeneric_;
  }

  void compositeTypeMarkUniqueStringsInner(Context* context) const {
  }

 public:
  virtual ~CompositeType() = 0; // this is an abstract base class

  bool isGeneric() const override { return isGeneric_; }
};


} // end namespace uast
} // end namespace chpl

#endif
