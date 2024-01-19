// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace Protocol {
class MoveInfo;
struct MoveInfoDefaultTypeInternal;
extern MoveInfoDefaultTypeInternal _MoveInfo_default_instance_;
class ObjectInfo;
struct ObjectInfoDefaultTypeInternal;
extern ObjectInfoDefaultTypeInternal _ObjectInfo_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::MoveInfo* Arena::CreateMaybeMessage<::Protocol::MoveInfo>(Arena*);
template<> ::Protocol::ObjectInfo* Arena::CreateMaybeMessage<::Protocol::ObjectInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class MoveInfo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.MoveInfo) */ {
 public:
  inline MoveInfo() : MoveInfo(nullptr) {}
  ~MoveInfo() override;
  explicit PROTOBUF_CONSTEXPR MoveInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MoveInfo(const MoveInfo& from);
  MoveInfo(MoveInfo&& from) noexcept
    : MoveInfo() {
    *this = ::std::move(from);
  }

  inline MoveInfo& operator=(const MoveInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline MoveInfo& operator=(MoveInfo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MoveInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const MoveInfo* internal_default_instance() {
    return reinterpret_cast<const MoveInfo*>(
               &_MoveInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MoveInfo& a, MoveInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(MoveInfo* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MoveInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MoveInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MoveInfo>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MoveInfo& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const MoveInfo& from) {
    MoveInfo::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MoveInfo* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.MoveInfo";
  }
  protected:
  explicit MoveInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kObjectIdFieldNumber = 1,
    kMoveTypeFieldNumber = 2,
    kSpeedFieldNumber = 3,
    kXFieldNumber = 4,
    kYFieldNumber = 5,
    kZFieldNumber = 6,
    kYawFieldNumber = 7,
  };
  // uint64 object_id = 1;
  void clear_object_id();
  uint64_t object_id() const;
  void set_object_id(uint64_t value);
  private:
  uint64_t _internal_object_id() const;
  void _internal_set_object_id(uint64_t value);
  public:

  // .Protocol.MoveType move_type = 2;
  void clear_move_type();
  ::Protocol::MoveType move_type() const;
  void set_move_type(::Protocol::MoveType value);
  private:
  ::Protocol::MoveType _internal_move_type() const;
  void _internal_set_move_type(::Protocol::MoveType value);
  public:

  // float speed = 3;
  void clear_speed();
  float speed() const;
  void set_speed(float value);
  private:
  float _internal_speed() const;
  void _internal_set_speed(float value);
  public:

  // float x = 4;
  void clear_x();
  float x() const;
  void set_x(float value);
  private:
  float _internal_x() const;
  void _internal_set_x(float value);
  public:

  // float y = 5;
  void clear_y();
  float y() const;
  void set_y(float value);
  private:
  float _internal_y() const;
  void _internal_set_y(float value);
  public:

  // float z = 6;
  void clear_z();
  float z() const;
  void set_z(float value);
  private:
  float _internal_z() const;
  void _internal_set_z(float value);
  public:

  // float yaw = 7;
  void clear_yaw();
  float yaw() const;
  void set_yaw(float value);
  private:
  float _internal_yaw() const;
  void _internal_set_yaw(float value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.MoveInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    uint64_t object_id_;
    int move_type_;
    float speed_;
    float x_;
    float y_;
    float z_;
    float yaw_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Struct_2eproto;
};
// -------------------------------------------------------------------

class ObjectInfo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.ObjectInfo) */ {
 public:
  inline ObjectInfo() : ObjectInfo(nullptr) {}
  ~ObjectInfo() override;
  explicit PROTOBUF_CONSTEXPR ObjectInfo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ObjectInfo(const ObjectInfo& from);
  ObjectInfo(ObjectInfo&& from) noexcept
    : ObjectInfo() {
    *this = ::std::move(from);
  }

  inline ObjectInfo& operator=(const ObjectInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline ObjectInfo& operator=(ObjectInfo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ObjectInfo& default_instance() {
    return *internal_default_instance();
  }
  static inline const ObjectInfo* internal_default_instance() {
    return reinterpret_cast<const ObjectInfo*>(
               &_ObjectInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ObjectInfo& a, ObjectInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(ObjectInfo* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ObjectInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ObjectInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ObjectInfo>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ObjectInfo& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ObjectInfo& from) {
    ObjectInfo::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ObjectInfo* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.ObjectInfo";
  }
  protected:
  explicit ObjectInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMoveInfoFieldNumber = 3,
    kObjectIdFieldNumber = 1,
    kObjectTypeFieldNumber = 2,
    kIsHostFieldNumber = 4,
  };
  // .Protocol.MoveInfo move_info = 3;
  bool has_move_info() const;
  private:
  bool _internal_has_move_info() const;
  public:
  void clear_move_info();
  const ::Protocol::MoveInfo& move_info() const;
  PROTOBUF_NODISCARD ::Protocol::MoveInfo* release_move_info();
  ::Protocol::MoveInfo* mutable_move_info();
  void set_allocated_move_info(::Protocol::MoveInfo* move_info);
  private:
  const ::Protocol::MoveInfo& _internal_move_info() const;
  ::Protocol::MoveInfo* _internal_mutable_move_info();
  public:
  void unsafe_arena_set_allocated_move_info(
      ::Protocol::MoveInfo* move_info);
  ::Protocol::MoveInfo* unsafe_arena_release_move_info();

  // uint64 object_id = 1;
  void clear_object_id();
  uint64_t object_id() const;
  void set_object_id(uint64_t value);
  private:
  uint64_t _internal_object_id() const;
  void _internal_set_object_id(uint64_t value);
  public:

  // .Protocol.ObjectType object_type = 2;
  void clear_object_type();
  ::Protocol::ObjectType object_type() const;
  void set_object_type(::Protocol::ObjectType value);
  private:
  ::Protocol::ObjectType _internal_object_type() const;
  void _internal_set_object_type(::Protocol::ObjectType value);
  public:

  // bool is_host = 4;
  void clear_is_host();
  bool is_host() const;
  void set_is_host(bool value);
  private:
  bool _internal_is_host() const;
  void _internal_set_is_host(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.ObjectInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::Protocol::MoveInfo* move_info_;
    uint64_t object_id_;
    int object_type_;
    bool is_host_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MoveInfo

// uint64 object_id = 1;
inline void MoveInfo::clear_object_id() {
  _impl_.object_id_ = uint64_t{0u};
}
inline uint64_t MoveInfo::_internal_object_id() const {
  return _impl_.object_id_;
}
inline uint64_t MoveInfo::object_id() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.object_id)
  return _internal_object_id();
}
inline void MoveInfo::_internal_set_object_id(uint64_t value) {
  
  _impl_.object_id_ = value;
}
inline void MoveInfo::set_object_id(uint64_t value) {
  _internal_set_object_id(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.object_id)
}

// .Protocol.MoveType move_type = 2;
inline void MoveInfo::clear_move_type() {
  _impl_.move_type_ = 0;
}
inline ::Protocol::MoveType MoveInfo::_internal_move_type() const {
  return static_cast< ::Protocol::MoveType >(_impl_.move_type_);
}
inline ::Protocol::MoveType MoveInfo::move_type() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.move_type)
  return _internal_move_type();
}
inline void MoveInfo::_internal_set_move_type(::Protocol::MoveType value) {
  
  _impl_.move_type_ = value;
}
inline void MoveInfo::set_move_type(::Protocol::MoveType value) {
  _internal_set_move_type(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.move_type)
}

// float speed = 3;
inline void MoveInfo::clear_speed() {
  _impl_.speed_ = 0;
}
inline float MoveInfo::_internal_speed() const {
  return _impl_.speed_;
}
inline float MoveInfo::speed() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.speed)
  return _internal_speed();
}
inline void MoveInfo::_internal_set_speed(float value) {
  
  _impl_.speed_ = value;
}
inline void MoveInfo::set_speed(float value) {
  _internal_set_speed(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.speed)
}

// float x = 4;
inline void MoveInfo::clear_x() {
  _impl_.x_ = 0;
}
inline float MoveInfo::_internal_x() const {
  return _impl_.x_;
}
inline float MoveInfo::x() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.x)
  return _internal_x();
}
inline void MoveInfo::_internal_set_x(float value) {
  
  _impl_.x_ = value;
}
inline void MoveInfo::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.x)
}

// float y = 5;
inline void MoveInfo::clear_y() {
  _impl_.y_ = 0;
}
inline float MoveInfo::_internal_y() const {
  return _impl_.y_;
}
inline float MoveInfo::y() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.y)
  return _internal_y();
}
inline void MoveInfo::_internal_set_y(float value) {
  
  _impl_.y_ = value;
}
inline void MoveInfo::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.y)
}

// float z = 6;
inline void MoveInfo::clear_z() {
  _impl_.z_ = 0;
}
inline float MoveInfo::_internal_z() const {
  return _impl_.z_;
}
inline float MoveInfo::z() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.z)
  return _internal_z();
}
inline void MoveInfo::_internal_set_z(float value) {
  
  _impl_.z_ = value;
}
inline void MoveInfo::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.z)
}

// float yaw = 7;
inline void MoveInfo::clear_yaw() {
  _impl_.yaw_ = 0;
}
inline float MoveInfo::_internal_yaw() const {
  return _impl_.yaw_;
}
inline float MoveInfo::yaw() const {
  // @@protoc_insertion_point(field_get:Protocol.MoveInfo.yaw)
  return _internal_yaw();
}
inline void MoveInfo::_internal_set_yaw(float value) {
  
  _impl_.yaw_ = value;
}
inline void MoveInfo::set_yaw(float value) {
  _internal_set_yaw(value);
  // @@protoc_insertion_point(field_set:Protocol.MoveInfo.yaw)
}

// -------------------------------------------------------------------

// ObjectInfo

// uint64 object_id = 1;
inline void ObjectInfo::clear_object_id() {
  _impl_.object_id_ = uint64_t{0u};
}
inline uint64_t ObjectInfo::_internal_object_id() const {
  return _impl_.object_id_;
}
inline uint64_t ObjectInfo::object_id() const {
  // @@protoc_insertion_point(field_get:Protocol.ObjectInfo.object_id)
  return _internal_object_id();
}
inline void ObjectInfo::_internal_set_object_id(uint64_t value) {
  
  _impl_.object_id_ = value;
}
inline void ObjectInfo::set_object_id(uint64_t value) {
  _internal_set_object_id(value);
  // @@protoc_insertion_point(field_set:Protocol.ObjectInfo.object_id)
}

// .Protocol.ObjectType object_type = 2;
inline void ObjectInfo::clear_object_type() {
  _impl_.object_type_ = 0;
}
inline ::Protocol::ObjectType ObjectInfo::_internal_object_type() const {
  return static_cast< ::Protocol::ObjectType >(_impl_.object_type_);
}
inline ::Protocol::ObjectType ObjectInfo::object_type() const {
  // @@protoc_insertion_point(field_get:Protocol.ObjectInfo.object_type)
  return _internal_object_type();
}
inline void ObjectInfo::_internal_set_object_type(::Protocol::ObjectType value) {
  
  _impl_.object_type_ = value;
}
inline void ObjectInfo::set_object_type(::Protocol::ObjectType value) {
  _internal_set_object_type(value);
  // @@protoc_insertion_point(field_set:Protocol.ObjectInfo.object_type)
}

// .Protocol.MoveInfo move_info = 3;
inline bool ObjectInfo::_internal_has_move_info() const {
  return this != internal_default_instance() && _impl_.move_info_ != nullptr;
}
inline bool ObjectInfo::has_move_info() const {
  return _internal_has_move_info();
}
inline void ObjectInfo::clear_move_info() {
  if (GetArenaForAllocation() == nullptr && _impl_.move_info_ != nullptr) {
    delete _impl_.move_info_;
  }
  _impl_.move_info_ = nullptr;
}
inline const ::Protocol::MoveInfo& ObjectInfo::_internal_move_info() const {
  const ::Protocol::MoveInfo* p = _impl_.move_info_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::MoveInfo&>(
      ::Protocol::_MoveInfo_default_instance_);
}
inline const ::Protocol::MoveInfo& ObjectInfo::move_info() const {
  // @@protoc_insertion_point(field_get:Protocol.ObjectInfo.move_info)
  return _internal_move_info();
}
inline void ObjectInfo::unsafe_arena_set_allocated_move_info(
    ::Protocol::MoveInfo* move_info) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.move_info_);
  }
  _impl_.move_info_ = move_info;
  if (move_info) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.ObjectInfo.move_info)
}
inline ::Protocol::MoveInfo* ObjectInfo::release_move_info() {
  
  ::Protocol::MoveInfo* temp = _impl_.move_info_;
  _impl_.move_info_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Protocol::MoveInfo* ObjectInfo::unsafe_arena_release_move_info() {
  // @@protoc_insertion_point(field_release:Protocol.ObjectInfo.move_info)
  
  ::Protocol::MoveInfo* temp = _impl_.move_info_;
  _impl_.move_info_ = nullptr;
  return temp;
}
inline ::Protocol::MoveInfo* ObjectInfo::_internal_mutable_move_info() {
  
  if (_impl_.move_info_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::MoveInfo>(GetArenaForAllocation());
    _impl_.move_info_ = p;
  }
  return _impl_.move_info_;
}
inline ::Protocol::MoveInfo* ObjectInfo::mutable_move_info() {
  ::Protocol::MoveInfo* _msg = _internal_mutable_move_info();
  // @@protoc_insertion_point(field_mutable:Protocol.ObjectInfo.move_info)
  return _msg;
}
inline void ObjectInfo::set_allocated_move_info(::Protocol::MoveInfo* move_info) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.move_info_;
  }
  if (move_info) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(move_info);
    if (message_arena != submessage_arena) {
      move_info = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, move_info, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.move_info_ = move_info;
  // @@protoc_insertion_point(field_set_allocated:Protocol.ObjectInfo.move_info)
}

// bool is_host = 4;
inline void ObjectInfo::clear_is_host() {
  _impl_.is_host_ = false;
}
inline bool ObjectInfo::_internal_is_host() const {
  return _impl_.is_host_;
}
inline bool ObjectInfo::is_host() const {
  // @@protoc_insertion_point(field_get:Protocol.ObjectInfo.is_host)
  return _internal_is_host();
}
inline void ObjectInfo::_internal_set_is_host(bool value) {
  
  _impl_.is_host_ = value;
}
inline void ObjectInfo::set_is_host(bool value) {
  _internal_set_is_host(value);
  // @@protoc_insertion_point(field_set:Protocol.ObjectInfo.is_host)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
