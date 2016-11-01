 #include "decodeur_audio.h"

decodeur_audio::decodeur_audio(opus_int32 frequence_opus, int cannaux)
    :m_erreur(0)
{
 m_decodeur=opus_decoder_create(frequence_opus,cannaux,&m_erreur);
}

decodeur_audio::~decodeur_audio()
{
opus_decoder_destroy(m_decodeur);
}

int decodeur_audio::get_error_decodeur_audio() const
{
    return m_erreur;
}

OpusDecoder& decodeur_audio::get_decodeur_audio()const
{
    return *m_decodeur;
}

int decodeur_audio::decodage_donnee_audio(const unsigned char*donnee_audio,opus_int32 taille_donnee_audio, opus_int16 *donnee_audio_decoder, int decode_fec )
{

return opus_decode(m_decodeur,donnee_audio,taille_donnee_audio,donnee_audio_decoder,TAILLE_ABSOLU,decode_fec);
}
