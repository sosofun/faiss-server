#ifndef FAISS_UTILS_H
#define FAISS_UTILS_H

#include <sys/types.h>  
#include <sys/stat.h>
#include <unistd.h>
#include <string>

static char* SPersistIDKey		= "PERSIST_ID";
static char* SMaxIDKey			= "MAX_ID";
static char* SBlackListKey		= "BLACKLIST_KEY";
static std::string SGlobalDBName = ".global";
static std::string SPrefix = "DB:";
static std::string SDivide = "##";
const uint64_t DefaultDBSize = 100000000;	
const uint64_t MaxDBSize     = 10000000000;	
const float EuclidThresh     = 30.0f;	
static int NProbes			 = 32;

const int FIXLEN = 10;

bool checkPathExists(std::string &path);

bool mkFolder(std::string &path);

//encode id to a fixed length string.
//idstr range is : 0000000000 ~ 9999999999
int encodeID(char *idstr, long id);

//decode idstr to a number
//return range is : 0 ~ 9999999999
//invalid idstr will return -1
long decodeID(char *idstr);

//calculate cosine distance between arr1 and arr2 subject to dimension d
float cosine(const float *arr1, const float *arr2, int d);

enum ErrorCode {
	/// Not an error; returned on success.
	OK = 0,

	/// The operation was cancelled (typically by the caller).
	CANCELLED = 1,

	/// Unknown error. An example of where this error may be returned is if a
	/// Status value received from another address space belongs to an error-space
	/// that is not known in this address space. Also errors raised by APIs that
	/// do not return enough error information may be converted to this error.
	UNKNOWN = 2,

	/// Client specified an invalid argument. Note that this differs from
	/// FAILED_PRECONDITION. INVALID_ARGUMENT indicates arguments that are
	/// problematic regardless of the state of the system (e.g., a malformed file
	/// name).
	INVALID_ARGUMENT = 3,

	/// Deadline expired before operation could complete. For operations that
	/// change the state of the system, this error may be returned even if the
	/// operation has completed successfully. For example, a successful response
	/// from a server could have been delayed long enough for the deadline to
	/// expire.
	DEADLINE_EXCEEDED = 4,

	/// Some requested entity (e.g., file or directory) was not found.
	NOT_FOUND = 5,

	/// Some entity that we attempted to create (e.g., file or directory) already
	/// exists.
	ALREADY_EXISTS = 6,

	/// The caller does not have permission to execute the specified operation.
	/// PERMISSION_DENIED must not be used for rejections caused by exhausting
	/// some resource (use RESOURCE_EXHAUSTED instead for those errors).
	/// PERMISSION_DENIED must not be used if the caller can not be identified
	/// (use UNAUTHENTICATED instead for those errors).
	PERMISSION_DENIED = 7,

	/// The request does not have valid authentication credentials for the
	/// operation.
	UNAUTHENTICATED = 16,

	/// Some resource has been exhausted, perhaps a per-user quota, or perhaps the
	/// entire file system is out of space.
	RESOURCE_EXHAUSTED = 8,

	/// Operation was rejected because the system is not in a state required for
	/// the operation's execution. For example, directory to be deleted may be
	/// non-empty, an rmdir operation is applied to a non-directory, etc.
	///
	/// A litmus test that may help a service implementor in deciding
	/// between FAILED_PRECONDITION, ABORTED, and UNAVAILABLE:
	///  (a) Use UNAVAILABLE if the client can retry just the failing call.
	///  (b) Use ABORTED if the client should retry at a higher-level
	///      (e.g., restarting a read-modify-write sequence).
	///  (c) Use FAILED_PRECONDITION if the client should not retry until
	///      the system state has been explicitly fixed. E.g., if an "rmdir"
	///      fails because the directory is non-empty, FAILED_PRECONDITION
	///      should be returned since the client should not retry unless
	///      they have first fixed up the directory by deleting files from it.
	///  (d) Use FAILED_PRECONDITION if the client performs conditional
	///      REST Get/Update/Delete on a resource and the resource on the
	///      server does not match the condition. E.g., conflicting
	///      read-modify-write on the same resource.
	FAILED_PRECONDITION = 9,

	/// The operation was aborted, typically due to a concurrency issue like
	/// sequencer check failures, transaction aborts, etc.
	///
	/// See litmus test above for deciding between FAILED_PRECONDITION, ABORTED,
	/// and UNAVAILABLE.
	ABORTED = 10,

	/// Operation was attempted past the valid range. E.g., seeking or reading
	/// past end of file.
	///
	/// Unlike INVALID_ARGUMENT, this error indicates a problem that may be fixed
	/// if the system state changes. For example, a 32-bit file system will
	/// generate INVALID_ARGUMENT if asked to read at an offset that is not in the
	/// range [0,2^32-1], but it will generate OUT_OF_RANGE if asked to read from
	/// an offset past the current file size.
	///
	/// There is a fair bit of overlap between FAILED_PRECONDITION and
	/// OUT_OF_RANGE. We recommend using OUT_OF_RANGE (the more specific error)
	/// when it applies so that callers who are iterating through a space can
	/// easily look for an OUT_OF_RANGE error to detect when they are done.
	OUT_OF_RANGE = 11,

	/// Operation is not implemented or not supported/enabled in this service.
	UNIMPLEMENTED = 12,

	/// Internal errors. Means some invariants expected by underlying System has
	/// been broken. If you see one of these errors, Something is very broken.
	INTERNAL = 13,

	/// The service is currently unavailable. This is a most likely a transient
	/// condition and may be corrected by retrying with a backoff.
	///
	/// See litmus test above for deciding between FAILED_PRECONDITION, ABORTED,
	/// and UNAVAILABLE.
	UNAVAILABLE = 14,

	/// Unrecoverable data loss or corruption.
	DATA_LOSS = 15,

	/// Force users to include a default branch:
	DO_NOT_USE = -1,

	/// Dimension not equal
	DIMENSION_NOT_EQUAL = 20,

	/// add feature failed
	ADD_FEATURE_FAILED = 21,

	/// exceeds max size
	EXCEEDS_MAX_SIZE = 22,
};
#endif
