#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForSVResult
///
#include "gen/GetQzssEphBoolParamForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForSVResult::CmdName = "GetQzssEphBoolParamForSVResult";
    const char* const GetQzssEphBoolParamForSVResult::Documentation = "Result of GetQzssEphBoolParamForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssEphBoolParamForSVResult);


    GetQzssEphBoolParamForSVResult::GetQzssEphBoolParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssEphBoolParamForSVResult::GetQzssEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }


    GetQzssEphBoolParamForSVResultPtr GetQzssEphBoolParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val)
    {
      return GetQzssEphBoolParamForSVResultPtr(new GetQzssEphBoolParamForSVResult(relatedCommand, svId, paramName, val));
    }

    GetQzssEphBoolParamForSVResultPtr GetQzssEphBoolParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForSVResult>(ptr);
    }

    bool GetQzssEphBoolParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
        ;

    }

    std::string GetQzssEphBoolParamForSVResult::documentation() const { return Documentation; }


    int GetQzssEphBoolParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssEphBoolParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssEphBoolParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssEphBoolParamForSVResult::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void GetQzssEphBoolParamForSVResult::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
