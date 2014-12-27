/**
 * spaintgui: Renderer.h
 */

#ifndef H_SPAINTGUI_RENDERER
#define H_SPAINTGUI_RENDERER

#include <SDL.h>

#include <rigging/MoveableCamera.h>

#include <spaint/SpaintEngine.h>

/**
 * \brief An instance of a class deriving from this one can be used to render the scene constructed by the spaint engine to a given target.
 */
class Renderer
{
  //#################### ENUMERATIONS ####################
public:
  /**
   * \brief TODO
   */
  enum CameraMode
  {
    /** TODO */
    CM_FOLLOW,

    /** TODO */
    CM_FREE
  };

  //#################### TYPEDEFS ####################
protected:
  typedef boost::shared_ptr<ITMUChar4Image> ITMUChar4Image_Ptr;
  typedef boost::shared_ptr<void> SDL_GLContext_Ptr;
  typedef boost::shared_ptr<SDL_Window> SDL_Window_Ptr;

  //#################### PROTECTED VARIABLES ####################
protected:
  /** TODO */
  CameraMode m_cameraMode;

  /** The OpenGL context for the window. */
  SDL_GLContext_Ptr m_context;

  /** The spaint engine. */
  spaint::SpaintEngine_Ptr m_spaintEngine;

  /** The window into which to render. */
  SDL_Window_Ptr m_window;

  //#################### CONSTRUCTORS ####################
public:
  /**
   * \brief Constructs a renderer.
   *
   * \param spaintEngine  The spaint engine.
   */
  explicit Renderer(const spaint::SpaintEngine_Ptr& spaintEngine)
  : m_cameraMode(CM_FOLLOW),
    m_spaintEngine(spaintEngine)
  {}

  //#################### DESTRUCTOR ####################
public:
  /**
   * \brief Destroys the renderer.
   */
  virtual ~Renderer() {}

  //#################### PUBLIC ABSTRACT MEMBER FUNCTIONS ####################
public:
  /**
   * \brief Gets the camera from which to render the scene.
   *
   * \return  The camera from which to render the scene.
   */
  virtual rigging::MoveableCamera_Ptr get_camera() = 0;

  /**
   * \brief Renders the scene.
   */
  virtual void render() const = 0;

  //#################### PUBLIC MEMBER FUNCTIONS ####################
public:
  /**
   * \brief TODO
   */
  CameraMode get_camera_mode() const
  {
    return m_cameraMode;
  }

  /**
   * \brief TODO
   */
  void set_camera_mode(CameraMode cameraMode)
  {
    m_cameraMode = cameraMode;
  }
};

#endif
