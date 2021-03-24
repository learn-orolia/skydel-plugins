#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoSignalHealthForSVResult
///
#include "gen/GetGalileoSignalHealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoSignalHealthForSVResult::CmdName = "GetGalileoSignalHealthForSVResult";
    const char* const GetGalileoSignalHealthForSVResult::Documentation = "Result of GetGalileoSignalHealthForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoSignalHealthForSVResult);


    GetGalileoSignalHealthForSVResult::GetGalileoSignalHealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGalileoSignalHealthForSVResult::GetGalileoSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& component, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
    }


    GetGalileoSignalHealthForSVResultPtr GetGalileoSignalHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& component, int health)
    {
      return GetGalileoSignalHealthForSVResultPtr(new GetGalileoSignalHealthForSVResult(relatedCommand, svId, component, health));
    }

    GetGalileoSignalHealthForSVResultPtr GetGalileoSignalHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoSignalHealthForSVResult>(ptr);
    }

    bool GetGalileoSignalHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGalileoSignalHealthForSVResult::documentation() const { return Documentation; }


    int GetGalileoSignalHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGalileoSignalHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoSignalHealthForSVResult::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoSignalHealthForSVResult::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoSignalHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGalileoSignalHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}