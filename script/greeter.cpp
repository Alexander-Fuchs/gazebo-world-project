#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <sdf/sdf.hh>
#include <iostream>

namespace gazebo
{
  class MyWorldPlugin : public WorldPlugin
  {
  public:
    void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf) override
    {
      // If you provide <welcome_name> in the SDF, use it; otherwise use the world name.
      std::string name;
      if (_sdf && _sdf->HasElement("welcome_name"))
        name = _sdf->Get<std::string>("welcome_name");
      else if (_world)
        name = _world->Name();
      else
        name = "Gazebo";

      std::cout << "Welcome to " << name << "'s World!" << std::endl;
    }
  };

  GZ_REGISTER_WORLD_PLUGIN(MyWorldPlugin)
}
