#include <d2d1.h>
#include <dwrite.h>

typedef struct {
  ID2D1SolidColorBrush* grayBrush;

} D2DDrawingResources;

typedef struct {
  ID2D1Factory* factory;
  IDWriteFactory* dwFactory;
  ID2D1HwndRenderTarget* hwndRenderTarget;
  D2DDrawingResources drawingResources;
} D2DResources;

HRESULT initD2DIndependentResources(D2DResources* resources) {
  HRESULT hr;
  hr =
      D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &resources->factory);
  hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
                           (IUnknown**)(&resources->dwFactory));

  return hr;
}

HRESULT initD2DResources(D2DResources* d2dResources, HWND hWnd) {
  if (d2dResources) {
    RECT rc;
    GetClientRect(hWnd, &rc);
    D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

    HRESULT hr = d2dResources->factory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(hWnd, size),
        &d2dResources->hwndRenderTarget);

    hr = d2dResources->hwndRenderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::LightSlateGray),
        &d2dResources->drawingResources.grayBrush);

    hr = d2dResources->dwFactory->CreateTextFormat()

    return hr;
  }
  return E_FAIL;
}

void calculateWH(D2DResources* resources, int w, int h, int* retW, int* retH) {
  FLOAT dpiX, dpiY;
  resources->factory->GetDesktopDpi(&dpiX, &dpiY);

  *retW = w * dpiX / 96.f;
  *retH = h * dpiY / 96.f;
}

void render(D2DResources* resources) {
  ID2D1HwndRenderTarget* target = resources->hwndRenderTarget;
  target->BeginDraw();
  target->SetTransform(D2D1::Matrix3x2F::Identity());
  target->Clear(D2D1::ColorF(D2D1::ColorF::White));

  D2D1_SIZE_F rtSize = target->GetSize();

  int width = int(rtSize.width);
  int height = int(rtSize.height);

  for (int x = 0; x < width; x += 10) {
    target->DrawLine(D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
                     D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
                     resources->drawingResources.grayBrush, 0.5f);
  }
  for (int y = 0; y < height; y += 10) {
    target->DrawLine(D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
                     D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
                     resources->drawingResources.grayBrush, 0.5f);
  }

  resources->hwndRenderTarget->EndDraw();
}

int freeD2DResources() {
  return 0;
}