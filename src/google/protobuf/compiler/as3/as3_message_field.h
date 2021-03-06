// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.
// http://code.google.com/p/protobuf/
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: kenton@google.com (Kenton Varda)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, and others.

#ifndef GOOGLE_PROTOBUF_COMPILER_AS3_MESSAGE_FIELD_H__
#define GOOGLE_PROTOBUF_COMPILER_AS3_MESSAGE_FIELD_H__

#include <map>
#include <string>
#include <google/protobuf/compiler/as3/as3_field.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace as3 {

class MessageFieldGenerator : public FieldGenerator {
 public:
  explicit MessageFieldGenerator(const FieldDescriptor* descriptor);
  ~MessageFieldGenerator();

  // implements FieldGenerator ---------------------------------------
  void GenerateMembers(io::Printer* printer) const;
  void GenerateBuilderMembers(io::Printer* printer) const;
  void GenerateMergingCode(io::Printer* printer) const;
  void GenerateBuildingCode(io::Printer* printer) const;
  void GenerateParsingCode(io::Printer* printer) const;
  void GenerateSerializationCode(io::Printer* printer) const;
  void GenerateSerializedSizeCode(io::Printer* printer) const;

  string GetBoxedType() const;

 private:
  const FieldDescriptor* descriptor_;
  map<string, string> variables_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(MessageFieldGenerator);
};

class RepeatedMessageFieldGenerator : public FieldGenerator {
 public:
  explicit RepeatedMessageFieldGenerator(const FieldDescriptor* descriptor);
  ~RepeatedMessageFieldGenerator();

  // implements FieldGenerator ---------------------------------------
  void GenerateMembers(io::Printer* printer) const;
  void GenerateBuilderMembers(io::Printer* printer) const;
  void GenerateMergingCode(io::Printer* printer) const;
  void GenerateBuildingCode(io::Printer* printer) const;
  void GenerateParsingCode(io::Printer* printer) const;
  void GenerateSerializationCode(io::Printer* printer) const;
  void GenerateSerializedSizeCode(io::Printer* printer) const;

  string GetBoxedType() const;

 private:
  const FieldDescriptor* descriptor_;
  map<string, string> variables_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RepeatedMessageFieldGenerator);
};

}  // namespace as3
}  // namespace compiler
}  // namespace protobuf

}  // namespace google
#endif  // GOOGLE_PROTOBUF_COMPILER_AS3_MESSAGE_FIELD_H__
