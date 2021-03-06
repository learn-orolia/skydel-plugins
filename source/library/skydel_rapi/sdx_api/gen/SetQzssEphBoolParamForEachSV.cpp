#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssEphBoolParamForEachSV
///
#include "gen/SetQzssEphBoolParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssEphBoolParamForEachSV::CmdName = "SetQzssEphBoolParamForEachSV";
    const char* const SetQzssEphBoolParamForEachSV::Documentation = "Please note the command SetQzssEphemerisBoolParams is deprecated since 21.3. You may use SetQzssEphBoolParamForEachSV.\n\nSet QZSS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetQzssEphBoolParamForEachSV);


    SetQzssEphBoolParamForEachSV::SetQzssEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetQzssEphBoolParamForEachSV::SetQzssEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
    }


    SetQzssEphBoolParamForEachSVPtr SetQzssEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val)
    {
      return SetQzssEphBoolParamForEachSVPtr(new SetQzssEphBoolParamForEachSV(paramName, val));
    }

    SetQzssEphBoolParamForEachSVPtr SetQzssEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssEphBoolParamForEachSV>(ptr);
    }

    bool SetQzssEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
        ;

    }

    std::string SetQzssEphBoolParamForEachSV::documentation() const { return Documentation; }


    int SetQzssEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetQzssEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetQzssEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetQzssEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
