/**
 * FILE: udf.h
 * -------------
 * Enocoders and decoders must be specified via a single-line comment of 
 * the form <@@f_type: message_type> just above the function declaration.
 * Encoders/Decoders must always be passed the size of encoded data by reference.
 * Refer to decodesupi() for your decoders.
 * 
 * @@keygen: Necessary for every Pyramis NF. Every timer must have atleast a procedurekey,
 * i.e. a variable that contains the result of a call to a keygen. 
*/
#ifndef __UDF_H__
#define __UDF_H__

// All headers are user-defined.
// udf cant have any dependencies on the platform file
#include <vector>
//#include "./generated/synerp_platform.h"
#include "../utility_library/synerp_messages.h"

//@@encoder: SynerPMessageHeader_t
void SynerPMessageHeaderEncode(std::vector<char>& buffer, SynerPMessageHeader_t &msg_struct, size_t &buffer_size);

//@@decoder: SynerPMessageHeader_t
void SynerPMessageHeaderDecode(SynerPMessageHeader_t &msg_struct, std::vector<char>& message, size_t &buffer_size);

//@@encoder: SynerPMessage_t
void SynerPMessageEncode(std::vector<char>& buffer, SynerPMessage_t &msg_struct, size_t &buffer_size);

//@@decoder: SynerPMessage_t
void SynerPMessageDecode(SynerPMessage_t &msg_struct, std::vector<char>& buffer, size_t &buffer_size);

// create a custom response string
std::string generate_login_response(_e_SynerPLoginResponse r_type);

std::string get_timer_name(_e_TimerType t_type);
std::string generate_timer_response(std::string userID, _e_TimerType t_type, _e_SynerPLoginResponse r_type);

//@@keygen
int generate_procedure_key();

#endif