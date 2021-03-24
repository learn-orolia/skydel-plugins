#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1cHealthForSV
///
#include "gen/SetQzssL1cHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1cHealthForSV::CmdName = "SetQzssL1cHealthForSV";
    const char* const SetQzssL1cHealthForSV::Documentation = "Please note the command SetQzssSatelliteL1cHealth is deprecated since 21.3. You may use SetQzssL1cHealthForSV.\n\nSet QZSS L1C health (Health of L1C signal)";

    REGISTER_COMMAND_FACTORY(SetQzssL1cHealthForSV);


    SetQzssL1cHealthForSV::SetQzssL1cHealthForSV()
      : CommandBase(CmdName)
    {}

    SetQzssL1cHealthForSV::SetQzssL1cHealthForSV(int svId, bool health)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
    }


    SetQzssL1cHealthForSVPtr SetQzssL1cHealthForSV::create(int svId, bool health)
    {
      return SetQzssL1cHealthForSVPtr(new SetQzssL1cHealthForSV(svId, health));
    }

    SetQzssL1cHealthForSVPtr SetQzssL1cHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1cHealthForSV>(ptr);
    }

    bool SetQzssL1cHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string SetQzssL1cHealthForSV::documentation() const { return Documentation; }


    int SetQzssL1cHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetQzssL1cHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetQzssL1cHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL1cHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetQzssL1cHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}